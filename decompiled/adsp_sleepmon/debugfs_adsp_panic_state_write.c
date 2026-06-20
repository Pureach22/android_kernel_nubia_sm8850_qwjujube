__int64 __fastcall debugfs_adsp_panic_state_write(__int64 a1, char a2)
{
  char v2; // w8
  __int64 result; // x0
  void *v4; // x0

  if ( !qword_A680 || (unsigned int)dword_A678 <= 1 )
  {
    v4 = &unk_99E9;
    goto LABEL_14;
  }
  byte_A632 = a2 & 1;
  byte_A633 = (a2 & 2) != 0;
  byte_A634 = (a2 & 4) != 0;
  if ( (a2 & 8) != 0 )
  {
    if ( qword_B138 )
    {
      if ( (a2 & 1) != 0 || (a2 & 2) != 0 || (a2 & 4) != 0 )
      {
        v2 = 1;
        goto LABEL_10;
      }
      v4 = &unk_936D;
    }
    else
    {
      v4 = &unk_9CDA;
    }
LABEL_14:
    printk(v4);
    return 4294967274LL;
  }
  v2 = 0;
LABEL_10:
  result = 0;
  byte_A635 = v2;
  return result;
}
