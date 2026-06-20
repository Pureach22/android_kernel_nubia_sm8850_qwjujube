__int64 __fastcall sub_69BF78(__int64 a1)
{
  __int16 v1; // w12

  if ( (v1 & 0x200) == 0 )
    JUMPOUT(0x69F57C);
  return osif_dp_register_stc_callbacks(a1);
}
