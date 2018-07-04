#include <thread>
#include <chrono>

#include "fmt/format.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "prometheus/exposer.h"
#include "prometheus/registry.h"

#include "utilities/Timer.h"

using namespace prometheus;

using namespace std;
using namespace std::chrono_literals;

int main() {
  auto logger = spdlog::stderr_color_mt("console");

  Timer uptime(1s, [] () {
    spdlog::get("console")->info("HEARTBEAT");
  });

  uptime.start();
  this_thread::sleep_for(10s);
  uptime.stop();

  logger->info("Shutting down.");

  return 0;
}