__int64 __fastcall a6xx_hfi_send_bcl_feature_ctrl(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 20437) == 1 )
    return a6xx_hfi_send_feature_ctrl(a1, 11, 1, 0);
  else
    return 0;
}
