__int64 __fastcall gen7_hfi_send_lpac_feature_ctrl(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 20440) == 1 )
    return gen7_hfi_send_feature_ctrl(a1, 24, 1, 0);
  else
    return 0;
}
