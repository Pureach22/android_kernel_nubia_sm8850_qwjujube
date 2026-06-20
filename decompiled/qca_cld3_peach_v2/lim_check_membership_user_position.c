__int64 __fastcall lim_check_membership_user_position(__int64 a1, __int64 a2, int a3, int a4)
{
  unsigned __int16 v7; // w8
  __int16 v8; // w8
  int v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+4h] [xbp-1Ch] BYREF
  int v12; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a2 + 10);
  v12 = a3;
  v13[0] = v7;
  v11 = 0;
  qdf_mem_copy((char *)v13 + 2, (const void *)(a2 + 24), 6u);
  lim_set_membership(a1, &v12, a2);
  v8 = *(unsigned __int8 *)(a2 + 10);
  v10 = a4;
  LOWORD(v11) = v8;
  qdf_mem_copy((char *)&v11 + 2, (const void *)(a2 + 24), 6u);
  lim_set_user_pos(a1, &v10, a2);
  _ReadStatusReg(SP_EL0);
  return 1;
}
