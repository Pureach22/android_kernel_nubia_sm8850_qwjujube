unsigned __int64 __fastcall sde_dbg_power_wakelock_wr(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v6; // x20
  size_t v7; // x22
  int v9; // [xsp+0h] [xbp-110h] BYREF
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v11; // [xsp+108h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( a1
    && (v6 = *(_QWORD *)(a1 + 32)) != 0
    && (a3 >= 0x100 ? (v7 = 256) : (v7 = a3),
        (v9 = 0, _check_object_size(s, v7, 0), !inline_copy_from_user_5((int)s, a2, v7))
     && (s[v7] = 0, !(unsigned int)kstrtouint(s, 0, &v9))) )
  {
    sde_power_wakelock_ctrl(v6, v9 != 0);
  }
  else
  {
    a3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
