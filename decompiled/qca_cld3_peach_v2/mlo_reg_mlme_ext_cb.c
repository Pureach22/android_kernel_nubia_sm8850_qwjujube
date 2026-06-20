__int64 __fastcall mlo_reg_mlme_ext_cb(__int64 a1, __int64 a2)
{
  if ( !a1 )
    return 16;
  *(_QWORD *)(a1 + 352) = a2;
  return 0;
}
