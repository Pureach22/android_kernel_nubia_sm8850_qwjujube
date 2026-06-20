__int64 __fastcall dp_panel_setup_hdr(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 v4; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x9
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x8
  int v15; // w0
  unsigned int v16; // w9
  unsigned int v17; // w10
  int v18; // w8
  __int64 v19; // x9
  __int64 v20; // x0
  void (__fastcall *v21)(_QWORD); // x9
  __int64 v22; // x0
  void (__fastcall *v23)(_QWORD); // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v26 = 0;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_setup_hdr");
    result = 4294967274LL;
    goto LABEL_18;
  }
  v4 = *(_QWORD *)(a1 + 1216);
  if ( a2 )
  {
    *(_DWORD *)(a1 + 1236) = *(_DWORD *)a2;
    *(_DWORD *)(v4 + 72) = 1277003520;
    if ( *(_DWORD *)(a1 + 1236) )
    {
      v7 = *(_QWORD *)(a2 + 8);
      *(_QWORD *)(v4 + 80) = *(_QWORD *)a2;
      *(_QWORD *)(v4 + 88) = v7;
      v8 = *(_QWORD *)(a2 + 40);
      v9 = *(_QWORD *)(a2 + 16);
      v10 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(v4 + 112) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(v4 + 120) = v8;
      *(_QWORD *)(v4 + 96) = v9;
      *(_QWORD *)(v4 + 104) = v10;
      v11 = *(_QWORD *)(a2 + 72);
      v12 = *(_QWORD *)(a2 + 48);
      v13 = *(_QWORD *)(a2 + 56);
      *(_QWORD *)(v4 + 144) = *(_QWORD *)(a2 + 64);
      *(_QWORD *)(v4 + 152) = v11;
      *(_QWORD *)(v4 + 128) = v12;
      *(_QWORD *)(v4 + 136) = v13;
      if ( (a3 & 1) == 0 )
      {
LABEL_10:
        if ( *(_BYTE *)(a1 + 1232) == 1 )
        {
          *(_DWORD *)(*(_QWORD *)(a1 + 1216) + 204LL) = *(_DWORD *)(a1 + 912);
          v20 = *(_QWORD *)(a1 + 1216);
          v21 = *(void (__fastcall **)(_QWORD))(v20 + 600);
          if ( *((_DWORD *)v21 - 1) != -1289009084 )
            __break(0x8229u);
          v21(v20);
          if ( (a3 & 1) != 0 )
          {
            v22 = *(_QWORD *)(a1 + 1216);
            v23 = *(void (__fastcall **)(_QWORD))(v22 + 696);
            if ( *((_DWORD *)v23 - 1) != 440525842 )
              __break(0x8228u);
            v23(v22);
          }
        }
        goto LABEL_17;
      }
    }
    else
    {
      *(_QWORD *)(v4 + 144) = 0;
      *(_QWORD *)(v4 + 152) = 0;
      *(_QWORD *)(v4 + 128) = 0;
      *(_QWORD *)(v4 + 136) = 0;
      *(_QWORD *)(v4 + 112) = 0;
      *(_QWORD *)(v4 + 120) = 0;
      *(_QWORD *)(v4 + 96) = 0;
      *(_QWORD *)(v4 + 104) = 0;
      *(_QWORD *)(v4 + 80) = 0;
      *(_QWORD *)(v4 + 88) = 0;
      if ( (a3 & 1) == 0 )
        goto LABEL_10;
    }
LABEL_8:
    v14 = *(_QWORD *)(a1 + 1216);
    LODWORD(v26) = a4;
    *(_DWORD *)(v14 + 68) = 1277001984;
    v15 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(*(_QWORD *)(a1 + 1200) + 132LL));
    v16 = *(_DWORD *)(a1 + 152);
    v17 = *(_DWORD *)(a1 + 104);
    v18 = *(_DWORD *)(*(_QWORD *)(a1 + 1200) + 128LL);
    HIDWORD(v26) = v15;
    v27 = __PAIR64__(v17, v16);
    v19 = *(_QWORD *)(a1 + 888);
    LODWORD(v28) = v18;
    LOBYTE(v18) = *(_BYTE *)(a1 + 971);
    v29 = v19;
    LOBYTE(v19) = *(_BYTE *)(a1 + 968);
    LOBYTE(v30) = v18;
    BYTE1(v30) = v19;
    dp_tu_dhdr_pkt_limit(&v26);
    goto LABEL_10;
  }
  if ( *(_DWORD *)(v4 + 80) )
  {
    if ( (a3 & 1) == 0 )
      goto LABEL_10;
    goto LABEL_8;
  }
LABEL_17:
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
