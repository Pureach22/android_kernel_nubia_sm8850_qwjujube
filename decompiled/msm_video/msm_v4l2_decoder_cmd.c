__int64 __fastcall msm_v4l2_decoder_cmd(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v4; // x8
  __int64 *v5; // x1
  __int64 *inst_ref; // x0
  __int64 v7; // x19
  __int64 v8; // x4
  unsigned int v9; // w20
  __int64 v10; // x4
  _DWORD *v11; // x9
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4

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
    v7 = (__int64)inst_ref;
    client_lock((__int64)inst_ref);
    inst_lock(v7);
    if ( *(_DWORD *)(v7 + 160) == 5 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_94D1A, "err ", v7 + 340, "msm_v4l2_decoder_cmd", v8);
      v9 = -16;
    }
    else
    {
      if ( a3 )
      {
        v10 = *a3;
        if ( (unsigned int)v10 < 2 )
        {
          v11 = *(_DWORD **)(v7 + 168);
          if ( (_DWORD)v10 )
            v12 = 7;
          else
            v12 = 6;
          if ( *(v11 - 1) != -249828064 )
            __break(0x8229u);
          v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v11)(v7, v12, 0);
          goto LABEL_27;
        }
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_95AA5, "err ", v7 + 340, "msm_v4l2_decoder_cmd", v10);
      }
      else if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8BE9D, "err ", v7 + 340, "msm_v4l2_decoder_cmd", v8);
      }
      v9 = -22;
    }
LABEL_27:
    inst_unlock(v7);
    client_unlock(v7);
    put_inst(v7, v13, v14, v15, v16);
    return v9;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_961DD, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_decoder_cmd");
  return (unsigned int)-22;
}
