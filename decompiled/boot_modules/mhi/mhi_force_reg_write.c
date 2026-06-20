__int64 __fastcall mhi_force_reg_write(__int64 result)
{
  if ( (*(_BYTE *)(result + 340) & 8) == 0 )
    return flush_work(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 120LL);
  return result;
}
