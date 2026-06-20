__int64 __fastcall rmnet_core_genl_pid_boost_req_hdlr(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x23
  _DWORD *v7; // x8
  __int64 v8; // x27
  int v9; // w28
  __int64 v10; // x1
  _QWORD *v11; // x8
  _DWORD v12[100]; // [xsp+0h] [xbp-1A0h] BYREF
  __int64 v13; // [xsp+190h] [xbp-10h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2
    && (memset(v12, 0, sizeof(v12)), (v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 32LL)) != 0)
    && (int)nla_memcpy(v12, v3, 400) >= 1 )
  {
    result = 0;
    if ( BYTE2(v12[98]) && LOWORD(v12[98]) )
    {
      v5 = 0;
      if ( LOWORD(v12[98]) >= 0x20u )
        v6 = 32;
      else
        v6 = LOWORD(v12[98]);
      do
      {
        v7 = &v12[3 * v5];
        if ( *v7 )
        {
          v8 = (unsigned int)v7[1];
          v9 = v7[2];
          v10 = raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
          v11 = &rmnet_pid_ht[(unsigned int)(1640531527 * v9) >> 24];
          while ( 1 )
          {
            v11 = (_QWORD *)*v11;
            if ( !v11 )
              break;
            if ( *((_DWORD *)v11 + 16) == v9 )
            {
              *((_DWORD *)v11 + 15) = 1;
              v11[6] = v8;
              break;
            }
          }
          raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock, v10);
        }
        ++v5;
      }
      while ( v5 < v6 );
      result = 0;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
