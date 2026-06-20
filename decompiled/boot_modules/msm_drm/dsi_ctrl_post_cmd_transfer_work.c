__int64 __fastcall dsi_ctrl_post_cmd_transfer_work(__int64 a1)
{
  __int64 result; // x0

  result = dsi_ctrl_post_cmd_transfer(a1 - 2808);
  *(_BYTE *)(a1 + 40) = 0;
  return result;
}
