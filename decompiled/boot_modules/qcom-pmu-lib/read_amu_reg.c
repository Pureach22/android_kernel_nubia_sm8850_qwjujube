__int64 __fastcall read_amu_reg(__int64 result)
{
  int v1; // w1

  v1 = *(_DWORD *)result;
  if ( *(int *)result > 1 )
  {
    if ( v1 == 2 )
    {
      *(_QWORD *)(result + 8) = _ReadStatusReg(AMEVCNTR02_EL0);
      return result;
    }
    if ( v1 == 3 )
    {
      *(_QWORD *)(result + 8) = _ReadStatusReg(AMEVCNTR03_EL0);
      return result;
    }
  }
  else
  {
    if ( !v1 )
    {
      *(_QWORD *)(result + 8) = _ReadStatusReg(AMEVCNTR01_EL0);
      return result;
    }
    if ( v1 == 1 )
    {
      *(_QWORD *)(result + 8) = _ReadStatusReg(AMEVCNTR00_EL0);
      return result;
    }
  }
  return printk(&unk_9137);
}
