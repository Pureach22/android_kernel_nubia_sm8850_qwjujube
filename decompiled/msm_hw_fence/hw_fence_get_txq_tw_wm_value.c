__int64 __fastcall hw_fence_get_txq_tw_wm_value(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x30

  if ( a1 && a2 && *(_DWORD *)(a2 + 136) )
  {
    *a3 = *(_DWORD *)(*(_QWORD *)(a2 + 56) + 28LL);
    return 0;
  }
  else
  {
    printk(&unk_26248, "hw_fence_get_txq_tw_wm_value", 2874, v3, a1);
    return 4294967274LL;
  }
}
