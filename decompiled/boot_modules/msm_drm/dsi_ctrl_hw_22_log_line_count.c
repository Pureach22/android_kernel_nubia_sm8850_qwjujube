__int64 __fastcall dsi_ctrl_hw_22_log_line_count(__int64 a1, char a2)
{
  unsigned __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x9

  v2 = *(_QWORD *)(a1 + 48);
  result = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = 176;
    if ( (a2 & 1) != 0 )
      v4 = 688;
    return readl_relaxed_20((unsigned int *)(v2 + v4));
  }
  return result;
}
