__int64 __fastcall ipa3_eth_read_status(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w23
  __int64 result; // x0
  __int64 v6; // x28
  __int64 v7; // x25
  char v8; // w8
  char v9; // w22
  __int64 v10; // x11
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x10
  __int64 v14; // x13
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x9
  __int64 v19; // x11
  int v20; // w24
  __int64 v21; // x8
  __int64 v25; // [xsp+20h] [xbp-70h]
  __int64 v26; // [xsp+28h] [xbp-68h]
  __int64 v27; // [xsp+30h] [xbp-60h]
  __int64 v28; // [xsp+38h] [xbp-58h]
  __int64 v29; // [xsp+40h] [xbp-50h]
  __int64 v30; // [xsp+48h] [xbp-48h]
  __int64 v31; // [xsp+50h] [xbp-40h]
  __int64 v32; // [xsp+58h] [xbp-38h]
  __int64 v33; // [xsp+60h] [xbp-30h]
  __int64 v34; // [xsp+68h] [xbp-28h]
  __int64 v35; // [xsp+70h] [xbp-20h]
  __int64 v36; // [xsp+78h] [xbp-18h]
  __int64 v37; // [xsp+80h] [xbp-10h]
  __int64 v38; // [xsp+88h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
  {
    v4 = scnprintf(
           dbg_buff,
           4096,
           "%15s|%10s|%10s|%30s|%10s|%10s\n",
           "protocol",
           "instance",
           "pipe_hdl",
           "pipe_enum",
           "pipe_id",
           "ch_id");
    v6 = 0;
    while ( 1 )
    {
      v7 = 0;
      v8 = 1;
      do
      {
        v9 = v8;
        v10 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48960);
        v34 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48952);
        v35 = v10;
        v11 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48976);
        v12 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48928);
        v36 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48968);
        v37 = v11;
        v13 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48936);
        v14 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48944);
        v31 = v12;
        v32 = v13;
        v16 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48880);
        v15 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48888);
        v33 = v14;
        v25 = v16;
        v26 = v15;
        v17 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48904);
        v18 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48912);
        v19 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48920);
        v27 = *(_QWORD *)(ipa3_ctx + 208 * v6 + 104 * v7 + 48896);
        v28 = v17;
        v29 = v18;
        v30 = v19;
        if ( !(_BYTE)v25 )
          goto LABEL_7;
        v20 = *((unsigned __int8 *)&v27 + 20 * v7 + 4);
        if ( v20 == 1 )
        {
          if ( v4 >> 1 > 0x800 )
            goto LABEL_28;
          v4 += scnprintf(
                  &dbg_buff[v4],
                  (int)(4096 - v4),
                  "%15s|%10d|%10d|%30s|%10d|%10d\n",
                  ipa_eth_clients_strings[v6],
                  v7,
                  HIDWORD(v26),
                  ipa_clients_strings[SHIDWORD(v25)],
                  v26,
                  v27);
          if ( (unsigned __int8)v25 == 1 )
            goto LABEL_7;
          if ( v4 >> 1 > 0x800 )
            goto LABEL_28;
          v4 += scnprintf(
                  &dbg_buff[v4],
                  (int)(4096 - v4),
                  "%15s|%10d|%10d|%30s|%10d|%10d\n",
                  ipa_eth_clients_strings[v6],
                  v7,
                  v29,
                  ipa_clients_strings[(int)v28],
                  HIDWORD(v28),
                  HIDWORD(v29));
          if ( (unsigned __int8)v25 == 2 )
            goto LABEL_7;
          if ( v4 >> 1 > 0x800 )
            goto LABEL_28;
          v4 += scnprintf(
                  &dbg_buff[v4],
                  (int)(4096 - v4),
                  "%15s|%10d|%10d|%30s|%10d|%10d\n",
                  ipa_eth_clients_strings[v6],
                  v7,
                  HIDWORD(v31),
                  ipa_clients_strings[SHIDWORD(v30)],
                  v31,
                  v32);
          if ( (unsigned __int8)v25 == 3 )
            goto LABEL_7;
          if ( v4 >> 1 > 0x800 )
            goto LABEL_28;
          v4 += scnprintf(
                  &dbg_buff[v4],
                  (int)(4096 - v4),
                  "%15s|%10d|%10d|%30s|%10d|%10d\n",
                  ipa_eth_clients_strings[v6],
                  v7,
                  v34,
                  ipa_clients_strings[(int)v33],
                  HIDWORD(v33),
                  HIDWORD(v34));
          if ( (unsigned __int8)v25 == 4 )
            goto LABEL_7;
        }
        else
        {
          if ( (unsigned __int8)v25 < 5u )
            goto LABEL_7;
          if ( !*((_BYTE *)&v27 + 20 * v7 + 4) )
            goto LABEL_23;
        }
        if ( v4 >> 1 > 0x800 )
          goto LABEL_28;
        v4 += scnprintf(
                &dbg_buff[v4],
                (int)(4096 - v4),
                "%15s|%10d|%10d|%30s|%10d|%10d\n",
                ipa_eth_clients_strings[v6],
                v7,
                HIDWORD(v36),
                ipa_clients_strings[SHIDWORD(v35)],
                v36,
                v37);
LABEL_23:
        if ( (unsigned __int8)v25 != 5 )
        {
          v21 = (unsigned __int8)v25 - 5LL;
          while ( (v20 & 1) == 0 )
          {
            if ( !--v21 )
              goto LABEL_7;
          }
LABEL_28:
          __break(0x5512u);
        }
LABEL_7:
        v8 = 0;
        v7 = 1;
      }
      while ( (v9 & 1) != 0 );
      if ( ++v6 == 6 )
        goto LABEL_3;
    }
  }
  v4 = scnprintf(dbg_buff, 4096, "This feature only support on IPA4.5+\n");
LABEL_3:
  result = simple_read_from_buffer(a2, a3, a4, dbg_buff, (int)v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
