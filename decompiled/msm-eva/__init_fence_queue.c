__int64 __fastcall _init_fence_queue(__int64 a1)
{
  __int64 result; // x0

  _mutex_init(a1 + 15272, "&inst->fence_cmd_queue.lock", &_init_fence_queue___key);
  *(_QWORD *)(a1 + 15328) = a1 + 15328;
  *(_QWORD *)(a1 + 15336) = a1 + 15328;
  *(_QWORD *)(a1 + 15368) = a1 + 15368;
  *(_QWORD *)(a1 + 15376) = a1 + 15368;
  _init_waitqueue_head(a1 + 15344, "&inst->fence_cmd_queue.wq", &_init_fence_queue___key_49);
  *(_DWORD *)(a1 + 232) = 0;
  *(_QWORD *)(a1 + 15320) = 1;
  *(_QWORD *)(a1 + 248) = a1 + 248;
  *(_QWORD *)(a1 + 256) = a1 + 248;
  *(_DWORD *)(a1 + 240) = 0;
  result = _init_waitqueue_head(a1 + 264, "&inst->session_queue_fence.wq", &_init_fence_queue___key_51);
  *(_DWORD *)(a1 + 236) = 1;
  return result;
}
