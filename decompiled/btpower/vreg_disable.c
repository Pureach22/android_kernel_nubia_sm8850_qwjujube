__int64 __fastcall vreg_disable(__int64 result)
{
  _QWORD *v1; // x19
  int v2; // w8
  void *v3; // x8
  unsigned int v4; // w19

  if ( result )
  {
    v1 = (_QWORD *)result;
    if ( *(_BYTE *)(result + 28) == 1 )
    {
      LODWORD(result) = regulator_disable(*(_QWORD *)result);
      if ( (result & 0x80000000) != 0 )
      {
        v3 = &unk_13876;
        goto LABEL_13;
      }
      v2 = *((_DWORD *)v1 + 4);
      *((_BYTE *)v1 + 28) = 0;
      if ( v2 )
      {
        if ( *((_DWORD *)v1 + 5) )
        {
          LODWORD(result) = regulator_set_voltage(*v1, 0);
          if ( (result & 0x80000000) != 0 )
          {
            v3 = &unk_13848;
            goto LABEL_13;
          }
        }
      }
      result = regulator_set_load(*v1, 0);
      if ( (result & 0x80000000) != 0 )
      {
        v3 = &unk_132AE;
LABEL_13:
        v4 = result;
        printk(v3, "vreg_disable");
        return v4;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
