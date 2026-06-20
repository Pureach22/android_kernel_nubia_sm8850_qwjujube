__int64 __fastcall lim_send_eht_caps_ie(__int64 a1, __int64 a2, unsigned int a3)
{
  __int16 v6; // [xsp+8h] [xbp-58h] BYREF
  _BYTE v7[38]; // [xsp+Ah] [xbp-56h] BYREF
  __int16 v8; // [xsp+30h] [xbp-30h] BYREF
  _WORD v9[23]; // [xsp+32h] [xbp-2Eh] BYREF

  *(_QWORD *)&v9[19] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 38);
  memset(v7, 0, sizeof(v7));
  v8 = 3071;
  qdf_mem_copy(v9, "l", 1u);
  lim_set_eht_caps(a1, &v8, 40, 1, a3);
  lim_send_ie((unsigned __int8)a3, 255, 1, v9, (unsigned int)HIBYTE(v8) + 1);
  v6 = 3071;
  qdf_mem_copy(v7, "l", 1u);
  lim_set_eht_caps(a1, &v6, 40, 2, a3);
  lim_send_ie((unsigned __int8)a3, 255, 2, v7, (unsigned int)HIBYTE(v6) + 1);
  _ReadStatusReg(SP_EL0);
  return 0;
}
