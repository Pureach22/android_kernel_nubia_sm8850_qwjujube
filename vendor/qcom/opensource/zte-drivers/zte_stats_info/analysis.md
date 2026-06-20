# ZTE Stats Info Driver Analysis

## Overview
The `zte_stats_info` module is a customized stats collection driver that exposes a Generic Netlink family named `"ZTE_STATS"` to user-space listeners, providing active telemetry on PIDs and TGIDs (threads).

## Key Discoveries & GKI Workarounds
- **Netlink Interface:**
  - Family `"ZTE_STATS"` registers custom commands `ZTE_TASKSTATS_CMD_GET` and `ZTE_TASKSTATS_CMD_NEW`.
  - Exposes custom `zte_taskstats` payload (352 bytes) which contains detailed memory and scheduler statistics.
- **Sighand Locking Override:**
  - The standard Google GKI kernel does NOT export `__lock_task_sighand`. 
  - To work around this without breaking GKI compliance, we implemented `zte_lock_task_sighand` locally. This dereferences `tsk->sighand` under RCU protection and acquires `siglock` manually, achieving complete binary parity without depending on unexported GKI symbols.

## Verification
Successfully compiled targeting the Snapdragon 8 Gen 5 AOSP Clang toolchain without modpost warnings.
