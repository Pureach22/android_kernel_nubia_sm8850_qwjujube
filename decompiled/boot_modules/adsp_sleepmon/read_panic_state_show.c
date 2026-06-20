__int64 __fastcall read_panic_state_show(__int64 a1)
{
  int v1; // w8
  const char *v2; // x1
  __int64 v3; // x2

  v1 = (unsigned __int8)word_A62E | (2 * HIBYTE(word_A62E));
  if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      v2 = "\nPanic State: LPI Panic enabled\n";
      v3 = 32;
    }
    else
    {
      v2 = "\nPanic State: LPI and LPM Panics enabled\n";
      v3 = 41;
    }
  }
  else if ( v1 )
  {
    v2 = "\nPanic State: LPM Panic enabled\n";
    v3 = 32;
  }
  else
  {
    v2 = "\nPanic State: LPM and LPI panics Disabled\n";
    v3 = 42;
  }
  seq_write(a1, v2, v3);
  return 0;
}
