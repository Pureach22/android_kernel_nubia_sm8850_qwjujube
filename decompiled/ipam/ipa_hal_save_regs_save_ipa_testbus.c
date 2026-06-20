long double ipa_hal_save_regs_save_ipa_testbus()
{
  _QWORD *v0; // x25
  __int64 v1; // x0
  void (__fastcall *v2)(__int64, __int64); // x10
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w27
  __int64 v7; // x9
  __int64 v8; // x23
  __int64 v9; // x20
  __int64 (__fastcall *v10)(); // x8
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x8
  _QWORD *v14; // x22
  __int64 v15; // x0
  _DWORD *v16; // x9
  __int64 v17; // x25
  __int64 v18; // x0
  __int64 (__fastcall **v19)(); // x0
  __int64 v20; // x9
  __int64 (__fastcall **v21)(); // x24
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x27
  int v25; // w28
  __int64 v26; // x8
  __int64 v27; // x20
  __int64 (__fastcall *v28)(); // x8
  __int64 v29; // x0
  __int64 v30; // x0
  _DWORD *v31; // x9
  __int64 v32; // x25
  __int64 v33; // x0
  __int64 (__fastcall **v34)(); // x0
  __int64 v35; // x9
  __int64 (__fastcall **v36)(); // x24
  __int64 v37; // x0
  __int64 v38; // x0
  _DWORD *v39; // x10
  __int64 v40; // x19
  __int64 v41; // x0
  long double result; // q0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // [xsp+0h] [xbp-20h]
  __int64 v49; // [xsp+8h] [xbp-18h]
  __int64 v50; // [xsp+10h] [xbp-10h]
  __int64 v51; // [xsp+10h] [xbp-10h]
  __int64 v52; // [xsp+18h] [xbp-8h]
  __int64 v53; // [xsp+18h] [xbp-8h]

  v0 = &unk_207000;
  if ( qword_207070 )
  {
    v1 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343564);
    v2 = *(void (__fastcall **)(__int64, __int64))(v1 + 8);
    v3 = v1;
    v4 = *(_QWORD *)(ipa3_ctx + 44872) + 1343564LL;
    if ( *((_DWORD *)v2 - 1) != -1783303382 )
      __break(0x822Au);
    v2(v4, 1);
    if ( *(__int64 (__fastcall **)())(v3 + 8) == nop_write )
    {
      if ( ipa3_ctx )
      {
        v47 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v47 )
          ipc_log_string(v47, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343564);
      }
    }
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = 0;
      v9 = v5;
      v50 = v7;
      v52 = v5;
      do
      {
        v14 = v0;
        v15 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343564);
        v16 = *(_DWORD **)(v15 + 8);
        v17 = v15;
        v18 = *(_QWORD *)(ipa3_ctx + 44872) + 1343564LL;
        if ( *(v16 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v16)(v18, (unsigned int)(v6 + v8));
        if ( *(__int64 (__fastcall **)())(v17 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v22 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v22 )
              ipc_log_string(v22, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343564);
          }
        }
        v0 = v14;
        *(_DWORD *)(v14[14] + v9) = v6 + v8;
        v19 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1343552);
        v10 = *v19;
        v20 = ipa3_ctx;
        if ( *v19 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v21 = v19;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              1343552);
            v10 = *v21;
            v20 = ipa3_ctx;
          }
          else
          {
            v10 = nop_read;
          }
        }
        v11 = *(_QWORD *)(v20 + 44872) + 1343552LL;
        if ( *((_DWORD *)v10 - 1) != -1536295579 )
          __break(0x8228u);
        v12 = ((__int64 (__fastcall *)(__int64))v10)(v11);
        v8 += 4096;
        v13 = v14[14] + v9;
        v9 += 520;
        *(_DWORD *)(v13 + 4) = v12;
      }
      while ( v8 != 0x100000 );
      v6 += 16;
      v7 = v50 + 1;
      v5 = v52 + 8;
    }
    while ( v50 != 64 );
    v23 = 0;
    v24 = 133124;
    do
    {
      v48 = v24;
      v49 = v23;
      v25 = 0;
      v26 = 0;
      do
      {
        v27 = 0;
        v53 = v26;
        v51 = v24;
        do
        {
          v30 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343564);
          v31 = *(_DWORD **)(v30 + 8);
          v32 = v30;
          v33 = *(_QWORD *)(ipa3_ctx + 44872) + 1343564LL;
          if ( *(v31 - 1) != -1783303382 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD))v31)(v33, (unsigned int)(v25 + v27));
          if ( *(__int64 (__fastcall **)())(v32 + 8) == nop_write )
          {
            if ( ipa3_ctx )
            {
              v37 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v37 )
                ipc_log_string(v37, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343564);
            }
          }
          *(_DWORD *)(v14[14] + v24 - 4) = v25 + v27;
          v34 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1343552);
          v28 = *v34;
          v35 = ipa3_ctx;
          if ( *v34 == nop_read )
          {
            if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
            {
              v36 = v34;
              ipc_log_string(
                *(_QWORD *)(ipa3_ctx + 34160),
                "ipa %s:%d nop read action for address 0x%X\n",
                "in_dword_masked",
                948,
                1343552);
              v28 = *v36;
              v35 = ipa3_ctx;
            }
            else
            {
              v28 = nop_read;
            }
          }
          v29 = *(_QWORD *)(v35 + 44872) + 1343552LL;
          if ( *((_DWORD *)v28 - 1) != -1536295579 )
            __break(0x8228u);
          v27 += 4096;
          *(_DWORD *)(v14[14] + v24) = ((__int64 (__fastcall *)(__int64))v28)(v29);
          v24 += 520;
        }
        while ( v27 != 266240 );
        v25 += 16;
        v26 = v53 + 1;
        v24 = v51 + 8;
      }
      while ( v53 != 64 );
      v23 = v49 + 1;
      v24 = v48 + 33800;
    }
    while ( v49 != 31 );
    v38 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343564);
    v39 = *(_DWORD **)(v38 + 8);
    v40 = v38;
    v41 = *(_QWORD *)(ipa3_ctx + 44872) + 1343564LL;
    if ( *(v39 - 1) != -1783303382 )
      __break(0x822Au);
    ((void (__fastcall *)(__int64, _QWORD))v39)(v41, 0);
    if ( *(__int64 (__fastcall **)())(v40 + 8) == nop_write && ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v43 )
        return ipc_log_string(v43, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343564);
    }
  }
  else
  {
    v44 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v45 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v45 )
      {
        result = ipc_log_string(
                   v45,
                   "ipa %s:%d ipa_reg_save.ipa.testbus was not allocated\n",
                   "ipa_hal_save_regs_save_ipa_testbus",
                   1645);
        v44 = ipa3_ctx;
      }
      v46 = *(_QWORD *)(v44 + 34160);
      if ( v46 )
        return ipc_log_string(
                 v46,
                 "ipa %s:%d ipa_reg_save.ipa.testbus was not allocated\n",
                 "ipa_hal_save_regs_save_ipa_testbus",
                 1645);
    }
  }
  return result;
}
