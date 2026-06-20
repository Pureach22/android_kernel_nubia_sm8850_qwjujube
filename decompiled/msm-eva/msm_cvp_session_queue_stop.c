__int64 __fastcall msm_cvp_session_queue_stop(_DWORD *a1)
{
  char v2; // w8

  raw_spin_lock(a1 + 44);
  if ( a1[45] == 3 )
  {
    raw_spin_unlock(a1 + 44);
  }
  else
  {
    v2 = BYTE1(msm_cvp_debug);
    a1[45] = 3;
    if ( (v2 & 0x20) != 0 && !msm_cvp_debug_out )
      printk(&unk_86285, "sess", a1, (unsigned int)(a1[81] ^ a1[80]));
    raw_spin_unlock(a1 + 44);
    _wake_up(a1 + 52, 3, 0, 0);
    cvp_fence_thread_stop((__int64)a1);
  }
  return 0;
}
