__int64 __fastcall dp_mon_soc_deinit_2_0(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 20112);
  if ( *(_BYTE *)(v1 + 852) == 1 )
  {
    result = dp_tx_mon_soc_deinit_2_0();
    *(_BYTE *)(v1 + 852) = 0;
  }
  return result;
}
