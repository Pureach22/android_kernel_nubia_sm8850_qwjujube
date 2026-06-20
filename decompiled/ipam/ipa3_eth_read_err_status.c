__int64 __fastcall ipa3_eth_read_err_status(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w9
  unsigned int v8; // w0
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // [xsp+18h] [xbp-28h] BYREF
  int v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h] BYREF
  int v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v7 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( v7 <= 0x10 && (v7 != 15 || *(_DWORD *)(ipa3_ctx + 32256) != 2) )
  {
    v9 = scnprintf(dbg_buff, 4096, "This feature only support on IPA4.5+\n");
LABEL_8:
    result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v9);
    goto LABEL_9;
  }
  if ( **(_DWORD **)(a1 + 32) <= 3u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64 *))ipa3_eth_get_status)(109, 5, &v15);
    ((void (__fastcall *)(__int64, __int64, __int64 *))ipa3_eth_get_status)(108, 5, &v13);
    v8 = scnprintf(
           dbg_buff,
           4096,
           "%s_RP=0x%x\n%s_WP=0x%x\n%s_err:%u (scratch %d)\n",
           off_EAF0[0],
           v15,
           off_EAF0[0],
           HIDWORD(v15),
           off_EAF0[0],
           v16,
           5);
    if ( v8 >> 1 >= 0x801 )
    {
      __break(0x5512u);
      JUMPOUT(0x9C8A4);
    }
    v9 = scnprintf(
           &dbg_buff[v8],
           (int)(4096 - v8),
           "%s_RP=0x%x\n%s_WP=0x%x\n%s_err:%u (scratch %d)\n",
           off_EAE8[0],
           v13,
           off_EAE8[0],
           HIDWORD(v13),
           off_EAE8[0],
           v14,
           5)
       + v8;
    goto LABEL_8;
  }
  printk(&unk_3C3A0F, "ipa3_eth_read_err_status");
  v11 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_15:
    result = 0;
    goto LABEL_9;
  }
  v12 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v12 )
  {
    ipc_log_string(v12, "ipa %s:%d Not supported\n", "ipa3_eth_read_err_status", 4229);
    v11 = ipa3_ctx;
  }
  result = *(_QWORD *)(v11 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Not supported\n", "ipa3_eth_read_err_status", 4229);
    goto LABEL_15;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
