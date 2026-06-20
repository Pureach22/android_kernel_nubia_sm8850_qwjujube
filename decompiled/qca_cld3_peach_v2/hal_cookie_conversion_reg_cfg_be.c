__int64 __fastcall hal_cookie_conversion_reg_cfg_be(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 74392) + 1800LL);
  if ( *((_DWORD *)v1 - 1) != -1425971550 )
    __break(0x8228u);
  return v1();
}
