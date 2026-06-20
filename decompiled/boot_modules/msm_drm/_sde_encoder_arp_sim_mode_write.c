unsigned __int64 __fastcall sde_encoder_arp_sim_mode_write(__int64 a1, int a2, unsigned __int64 a3)
{
  _DWORD *v3; // x22
  size_t v6; // x20
  unsigned int v8; // w8
  bool v9; // cc
  unsigned int v10; // [xsp+0h] [xbp-110h] BYREF
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v12; // [xsp+108h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( a1
    && (v3 = *(_DWORD **)(a1 + 32)) != nullptr
    && ((memset(s, 0, sizeof(s)), a3 >= 0x100) ? (v6 = 256) : (v6 = a3),
        _check_object_size(s, v6, 0),
        !inline_copy_from_user_3((int)s, a2, v6)) )
  {
    s[v6] = 0;
    if ( (unsigned int)kstrtouint(s, 0, &v10) || (v8 = v10, v9 = v10 > 2, v3[1221] = v10, v9) )
    {
      a3 = -14;
    }
    else if ( !v8 )
    {
      v3[1222] = v3[1220];
    }
  }
  else
  {
    a3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
