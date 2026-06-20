__int64 __fastcall hw_fence_ipcc_trigger_signal(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v4; // x11
  __int64 v5; // x10
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v10; // x26
  unsigned int v11; // w25
  const char *v12; // x21
  unsigned int v13; // w19
  __int64 v14; // x20

  v4 = *(_QWORD *)(a1 + 608);
  v5 = (unsigned int)(*(_DWORD *)(a1 + 624) * *(_DWORD *)(a1 + 620));
  v6 = a4 | (a3 << 16);
  v7 = v4 + (a2 << 12) + v5 + 12;
  if ( (~msm_hw_fence_debug_level & 0x10040) != 0 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
      goto LABEL_3;
LABEL_8:
    v13 = v6;
    v14 = v7;
    printk(&unk_242F0, "hw_fence_ipcc_trigger_signal", 608, (unsigned int)v6, v7);
    v7 = v14;
    v6 = v13;
    goto LABEL_3;
  }
  v10 = v4 + (a2 << 12) + v5 + 12;
  v11 = a4 | (a3 << 16);
  if ( a2 - 3 > 0xF )
    v12 = "UNKNOWN_PID";
  else
    v12 = off_2C380[a2 - 3];
  get_ipc_virt_client_name(a3);
  printk(&unk_23989, "hw_fence_ipcc_trigger_signal", 607, v12, a2);
  v7 = v10;
  v6 = v11;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    goto LABEL_8;
LABEL_3:
  result = writel_relaxed(v6, v7);
  __dsb(0xEu);
  return result;
}
