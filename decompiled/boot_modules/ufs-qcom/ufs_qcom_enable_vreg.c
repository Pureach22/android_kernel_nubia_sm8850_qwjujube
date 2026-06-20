__int64 __fastcall ufs_qcom_enable_vreg(_QWORD *a1)
{
  __int64 result; // x0

  if ( (*((_BYTE *)a1 + 17) & 1) != 0 )
    return 0;
  if ( a1 )
  {
    if ( (int)regulator_count_voltages(*a1) < 1
      || (result = regulator_set_load(*a1, *((unsigned int *)a1 + 5)), !(_DWORD)result) )
    {
      result = regulator_enable(*a1);
      if ( !(_DWORD)result )
        *((_BYTE *)a1 + 17) = 1;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
  return result;
}
