__int64 __fastcall sde_hdcp_1x_feature_supported(__int64 a1)
{
  char v1; // w0

  if ( a1 )
  {
    v1 = hdcp1_feature_supported(*(_QWORD *)(a1 + 1448));
  }
  else
  {
    printk(&unk_255B25, "sde_hdcp_1x_feature_supported");
    v1 = 1;
  }
  return v1 & 1;
}
