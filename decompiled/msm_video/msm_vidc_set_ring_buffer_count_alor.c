__int64 __fastcall msm_vidc_set_ring_buffer_count_alor(__int64 a1, unsigned int a2)
{
  __int64 v2; // x4
  __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v5; // w6
  __int64 v6; // x22
  bool v7; // cc
  __int64 v8; // x8
  __int64 (*v9)(void); // x8
  unsigned int v10; // w23
  __int64 v11; // x20
  int v12; // w0
  __int64 v13; // x4
  int v14; // w8
  __int64 v15; // x4
  __int64 v16; // x23
  unsigned int v17; // w24
  __int64 result; // x0
  __int64 v19; // x19
  unsigned int v20; // w20

  _ReadStatusReg(SP_EL0);
  v2 = *(unsigned int *)(a1 + 600);
  v3 = *(_QWORD *)(a1 + 320);
  v4 = *(_DWORD *)(a1 + 604) * v2;
  if ( *(_DWORD *)(a1 + 19474) <= *(_DWORD *)(a1 + 19642) )
    v5 = *(_DWORD *)(a1 + 19642);
  else
    v5 = *(_DWORD *)(a1 + 19474);
  v6 = a1 + 4320;
  v7 = v4 >> 14 >= 0x7E9 && v5 > 0x1D;
  if ( !v7 && (v4 < 0x7E9000 || v5 <= 0x77) && (v4 >> 10 < 0x7E9 || v5 <= 0x1DF) && (v4 < 0xE1000 || v5 < 0x3C0) )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v19 = a1;
      v20 = a2;
      printk(&unk_82894, "high", a1 + 340, "msm_vidc_set_ring_buffer_count_alor", v2);
      a2 = v20;
      a1 = v19;
      if ( v20 > 0xC5 )
        goto LABEL_38;
      goto LABEL_29;
    }
LABEL_28:
    if ( a2 > 0xC5 )
      goto LABEL_38;
    goto LABEL_29;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v16 = a1;
    v17 = a2;
    printk(&unk_8BB6B, "high", a1 + 340, "msm_vidc_set_ring_buffer_count_alor", v2);
    a2 = v17;
    a1 = v16;
    if ( !v3 )
      goto LABEL_32;
  }
  else if ( !v3 )
  {
    goto LABEL_32;
  }
  v8 = *(_QWORD *)(v3 + 6560);
  if ( v8 )
  {
    v9 = *(__int64 (**)(void))(v8 + 72);
    if ( v9 )
    {
      v10 = a2;
      v11 = a1;
      if ( *((_DWORD *)v9 - 1) != 1877020927 )
        __break(0x8228u);
      v12 = v9();
      a2 = v10;
      v14 = v12;
      a1 = v11;
      if ( v14 )
      {
        if ( v11 && (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_88A0F, "err ", v11 + 340, "msm_vidc_set_ring_buffer_count_alor", v13);
          a2 = v10;
          a1 = v11;
          if ( v10 > 0xC5 )
LABEL_38:
            __break(0x5512u);
LABEL_29:
          v15 = 0;
          *(_QWORD *)(v6 + 168LL * a2 + 32) = 0;
          if ( !a1 )
            goto LABEL_36;
          goto LABEL_34;
        }
        goto LABEL_28;
      }
    }
  }
LABEL_32:
  if ( a2 > 0xC5 )
    goto LABEL_38;
  v15 = *(unsigned int *)(v6 + 168LL * a2 + 32);
  if ( a1 )
  {
LABEL_34:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_80AF4, "high", a1 + 340, "msm_vidc_set_ring_buffer_count_alor", v15);
  }
LABEL_36:
  result = venus_hfi_session_property();
  _ReadStatusReg(SP_EL0);
  return result;
}
