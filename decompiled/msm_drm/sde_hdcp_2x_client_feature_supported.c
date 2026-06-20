__int64 __fastcall sde_hdcp_2x_client_feature_supported(__int64 a1)
{
  while ( *(_DWORD *)(a1 + 132) )
    usleep_range_state(1000, 1500, 2);
  return hdcp2_feature_supported(*(_QWORD *)(a1 + 152)) & 1;
}
