__int64 __fastcall rmnet_aps_genl_pdn_config_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x9
  unsigned int *v11; // x9
  unsigned int v12; // w12
  __int64 v13; // x9
  __int64 result; // x0
  int v15; // [xsp+0h] [xbp-60h] BYREF
  __int64 v16; // [xsp+4h] [xbp-5Ch]
  __int64 v17; // [xsp+Ch] [xbp-54h]
  __int64 v18; // [xsp+14h] [xbp-4Ch]
  int v19; // [xsp+1Ch] [xbp-44h]
  _QWORD v20[2]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v21; // [xsp+30h] [xbp-30h]
  __int64 v22; // [xsp+38h] [xbp-28h]
  __int64 v23; // [xsp+40h] [xbp-20h]
  __int64 v24; // [xsp+48h] [xbp-18h]
  __int64 v25; // [xsp+50h] [xbp-10h]
  __int64 v26; // [xsp+58h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_15;
  v2 = *(_QWORD *)(a2 + 32);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20[1] = 0;
  v21 = 0;
  v20[0] = 0;
  v3 = *(_QWORD *)(v2 + 24);
  if ( !v3 )
    goto LABEL_15;
  if ( (int)nla_memcpy(v20, v3, 56) >= 1 )
  {
    if ( (_DWORD)v21 && aps_packet_expire_kt != 1000000LL * (unsigned int)v21 )
      aps_packet_expire_kt = 1000000LL * (unsigned int)v21;
    v5 = dev_get_by_index(&init_net);
    if ( v5 )
    {
      v6 = v5;
      v7 = strncmp((const char *)(v5 + 296), "rmnet_data", 0xAu);
      if ( !(_DWORD)v7 )
        *(_BYTE *)(v6 + 3176) = (_DWORD)v21 != 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v10 = *(_QWORD *)(v6 + 1320);
      v11 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v10);
      do
        v12 = __ldxr(v11);
      while ( __stxr(v12 - 1, v11) );
      v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v13;
      if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v7, v8);
    }
    v19 = 0;
    v18 = 0;
    v17 = 0;
    v16 = 0;
    v15 = v20[0];
    result = rmnet_aps_send_msg(a2, 2u, 4u, 0x20u, (__int64)&v15, 0xCC0u);
  }
  else
  {
LABEL_15:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
