__int64 __fastcall hfi_core_lb_append_packet(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  _QWORD *v7; // x8
  _QWORD *v8; // x20
  _QWORD *v9; // t1
  unsigned int v10; // w19
  _QWORD *v11; // x21
  unsigned int v12; // w22
  __int64 v13; // x23
  unsigned int v14; // w24
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x19
  int v18; // w9
  int v19; // w10
  int v20; // w9
  unsigned int full_packet; // w20
  __int64 result; // x0
  void *v23; // x0
  __int64 v24; // x2
  unsigned __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h] BYREF
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( !a1 )
  {
    v23 = &unk_1E1F9;
    v24 = 523;
LABEL_21:
    printk(v23, "hfi_core_lb_append_packet", v24, v5);
    goto LABEL_22;
  }
  v6 = *(_QWORD *)(a2 + 792);
  if ( !v6 )
  {
    v23 = &unk_1A52F;
    v24 = 529;
    goto LABEL_21;
  }
  v9 = *(_QWORD **)(v6 + 120);
  v8 = (_QWORD *)(v6 + 120);
  v7 = v9;
  if ( v9 != v8 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v10 = a3;
      v11 = a1;
      v12 = a4;
      v13 = v5;
      v14 = a5;
      printk(&unk_19FC6, "hfi_core_lb_cmd_get_payload", 502, (unsigned int)a3);
      v7 = (_QWORD *)*v8;
      a1 = v11;
      a5 = v14;
      a4 = v12;
      a3 = v10;
      v5 = v13;
    }
    while ( v7 != v8 )
    {
      if ( v7 != &_ksymtab_hfi_core_cmds_rx_buf_get && *((_DWORD *)v7 - 6) == (_DWORD)a3 )
      {
        v15 = *a1;
        v16 = a1[2];
        v25 = __PAIR64__(a5, a3);
        v17 = v5;
        v29 = v15;
        LODWORD(v30) = v16;
        LODWORD(v26) = *((_DWORD *)v7 - 1);
        HIDWORD(v26) = a4;
        v18 = *((_DWORD *)v7 - 2);
        if ( v18 == 1 )
          v19 = 1;
        else
          v19 = 2;
        if ( v18 )
          v20 = v19;
        else
          v20 = 0;
        LODWORD(v27) = v20;
        HIDWORD(v27) = 4 * *((_DWORD *)v7 - 2);
        v28 = *(v7 - 2);
        full_packet = hfi_create_full_packet((__int64)&v29, (__int64)&v25, a3, a4, a5);
        result = 0;
        if ( full_packet )
        {
          printk(&unk_1CF50, "hfi_core_lb_append_packet", 558, v17);
          result = full_packet;
        }
        goto LABEL_23;
      }
      v7 = (_QWORD *)*v7;
    }
  }
  printk(&unk_1A261, "hfi_core_lb_append_packet", 535, v5);
LABEL_22:
  result = 4294967274LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
