__int64 __fastcall msm_v4l2_poll(__int64 a1, _DWORD **a2)
{
  __int64 v4; // x8
  __int64 *v5; // x1
  __int64 *inst_ref; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned int v11; // w19
  __int64 *v12; // x21
  __int64 *v14; // x19

  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    if ( v4 )
      v5 = (__int64 *)(v4 - 1648);
    else
      v5 = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  inst_ref = get_inst_ref(g_core, v5);
  if ( inst_ref )
  {
    if ( *((_DWORD *)inst_ref + 40) == 5 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v14 = inst_ref;
        printk(&unk_94D1A, "err ", (char *)inst_ref + 340, "msm_v4l2_poll", v10);
        inst_ref = v14;
      }
      v11 = 8;
    }
    else
    {
      v12 = inst_ref;
      v11 = msm_vidc_poll(inst_ref, a1, a2);
      inst_ref = v12;
    }
    put_inst((__int64)inst_ref, v7, v8, v9, v10);
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_961DD, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_poll");
    return 8;
  }
  return v11;
}
