__int64 __fastcall sde_encoder_arp_sim_mode_read(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  signed int v10; // w0
  __int64 v11; // x21
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v13; // [xsp+108h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( *a4 )
    goto LABEL_2;
  if ( !a1 || (v9 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    result = -22;
    goto LABEL_10;
  }
  v10 = scnprintf(s, 257, "mode %d arp_te_time_in_ms %u\n", *(_DWORD *)(v9 + 4884), *(_DWORD *)(v9 + 4880));
  if ( (unsigned int)v10 > 0x100 )
  {
LABEL_2:
    result = 0;
  }
  else if ( a3 < 0x101 || (v11 = v10, _check_object_size(s, v10, 1), inline_copy_to_user_2(a2, s, v11)) )
  {
    result = -14;
  }
  else
  {
    result = v11;
    *a4 += v11;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
