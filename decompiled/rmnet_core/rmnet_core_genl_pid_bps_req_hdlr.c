__int64 __fastcall rmnet_core_genl_pid_bps_req_hdlr(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  bool v4; // w20
  __int64 v5; // x27
  __int64 v6; // x20
  __int64 v7; // x24
  unsigned __int64 v8; // x23
  __int16 v9; // w22
  __int64 *v10; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 *v13; // x28
  bool v14; // cf
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x10
  int v17; // w9
  int v18; // w9
  _OWORD *v19; // x11
  _QWORD *v20; // x8
  __int64 v22; // [xsp+0h] [xbp-440h] BYREF
  __int64 v23; // [xsp+8h] [xbp-438h]
  _OWORD v24[33]; // [xsp+10h] [xbp-430h] BYREF
  _BYTE s[528]; // [xsp+220h] [xbp-220h] BYREF
  __int64 v26; // [xsp+430h] [xbp-10h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v4 = !a2 || (v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 24LL)) == 0 || (int)nla_memcpy(s, v3, 528) < 1;
  if ( !rmnet_core_userspace_connected )
    rmnet_core_userspace_connected = 1;
  memset(v24, 0, sizeof(v24));
  if ( !v4 )
  {
    v22 = 0;
    v23 = 0;
    ktime_get_real_ts64(&v22);
    v5 = v23 + 1000000000 * v22;
    *(_QWORD *)&v24[32] = v5;
    v6 = raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
    v7 = 0;
    v8 = 0;
    v9 = 32;
    do
    {
      v10 = (__int64 *)rmnet_pid_ht[v7];
      if ( v10 )
      {
        do
        {
          while ( 1 )
          {
            v11 = v10[3];
            v12 = v10[4];
            v13 = (__int64 *)*v10;
            v14 = v11 >= v12;
            v15 = v11 - v12;
            if ( v15 != 0 && v14 )
              break;
            v20 = (_QWORD *)v10[1];
            if ( v20 )
            {
              *v20 = v13;
              if ( v13 )
                v13[1] = (__int64)v20;
              *v10 = 0;
              v10[1] = 0;
            }
            kfree(v10);
            v10 = v13;
            if ( !v13 )
              goto LABEL_9;
          }
          v16 = 8 * v15 / (unsigned int)((v5 - v10[2]) / 0x3B9ACA00uLL);
          v17 = *((_DWORD *)v10 + 14);
          if ( v17 <= 999 )
            v18 = 0;
          else
            v18 = v17 - 1000;
          *((_DWORD *)v10 + 14) = v18;
          v10[5] = v16;
          if ( v8 > 0x1F )
            goto LABEL_32;
          if ( ((16 * v8) | 8) > 0x210
            || (v19 = &v24[v8],
                *((_DWORD *)v19 + 2) = *((_DWORD *)v10 + 16),
                *(_QWORD *)v19 = v16,
                ((16 * v8) | 0xC) > 0x210) )
          {
            __break(1u);
LABEL_32:
            __break(0x5512u);
          }
          v5 = *(_QWORD *)&v24[32];
          *((_DWORD *)v19 + 3) = v18;
          v10[4] = v11;
          v10[2] = v5;
          if ( v8 == 31 )
            goto LABEL_29;
          ++v8;
          v10 = v13;
        }
        while ( v13 );
      }
LABEL_9:
      ++v7;
    }
    while ( v7 != 256 );
    v9 = v8;
LABEL_29:
    raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v6);
    WORD4(v24[32]) = v9;
  }
  BYTE10(v24[32]) = 1;
  rmnet_core_genl_send_resp(a2, (__int64)v24);
  _ReadStatusReg(SP_EL0);
  return 0;
}
