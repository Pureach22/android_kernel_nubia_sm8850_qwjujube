__int64 __fastcall read_adsp_panic_state_show(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  const char *v3; // x1
  __int64 v4; // x0
  __int64 v5; // x2
  const char *v6; // x1
  __int64 v7; // x2

  v1 = a1;
  if ( !qword_A680 || (unsigned int)dword_A678 <= 1 )
  {
    v6 = "\nADSP version doesn't support panic\n";
    v7 = 36;
    goto LABEL_14;
  }
  v2 = (unsigned __int8)byte_A632
     | (2 * (unsigned __int8)byte_A633)
     | (4 * (unsigned __int8)byte_A634)
     | (8 * (unsigned __int8)byte_A635);
  if ( (byte_A632 & 1) == 0 )
  {
    seq_write(a1, "\nADSP panic on LPM violation is disabled\n", 41);
    if ( (v2 & 2) != 0 )
      goto LABEL_5;
LABEL_9:
    seq_write(v1, "\nADSP panic on LPI violation is disabled\n", 41);
    if ( (v2 & 4) != 0 )
      goto LABEL_6;
    goto LABEL_10;
  }
  seq_write(a1, "\nADSP panic on LPM violation enabled\n", 37);
  if ( (v2 & 2) == 0 )
    goto LABEL_9;
LABEL_5:
  seq_write(v1, "\nADSP panic on LPI violation enabled\n", 37);
  if ( (v2 & 4) != 0 )
  {
LABEL_6:
    v3 = "\nADSP panic for LPM overall violation enabled\n";
    v4 = v1;
    v5 = 46;
    goto LABEL_11;
  }
LABEL_10:
  v3 = "\nADSP panic for LPM overall violation is disabled\n";
  v4 = v1;
  v5 = 50;
LABEL_11:
  seq_write(v4, v3, v5);
  if ( v2 >= 8 )
  {
    v6 = "\nADSP SSR config enabled\n";
    a1 = v1;
    v7 = 25;
  }
  else
  {
    v6 = "\nADSP SSR config disabled\n";
    a1 = v1;
    v7 = 26;
  }
LABEL_14:
  seq_write(a1, v6, v7);
  return 0;
}
