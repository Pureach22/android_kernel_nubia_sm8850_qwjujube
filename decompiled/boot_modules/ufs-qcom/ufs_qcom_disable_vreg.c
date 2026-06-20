__int64 __fastcall ufs_qcom_disable_vreg(__int64 result)
{
  _QWORD *v1; // x19

  if ( *(_BYTE *)(result + 17) == 1 )
  {
    v1 = (_QWORD *)result;
    result = regulator_disable(*(_QWORD *)result);
    if ( !(_DWORD)result )
    {
      if ( v1 )
      {
        result = regulator_count_voltages(*v1);
        if ( (int)result < 1 || (result = regulator_set_load(*v1, 0), !(_DWORD)result) )
          *((_BYTE *)v1 + 17) = 0;
      }
      else
      {
        __break(0x800u);
      }
    }
  }
  return result;
}
