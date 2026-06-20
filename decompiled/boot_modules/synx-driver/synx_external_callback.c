__int64 __fastcall synx_external_callback(__int64 result, unsigned int a2, unsigned int *a3)
{
  char v3; // w9
  unsigned int *v4; // x19

  if ( a3 && (unsigned __int64)a3 < 0xFFFFFFFFFFFFF001LL )
  {
    a3[1] = a2;
    v3 = synx_debug;
    *((_QWORD *)a3 + 1) = (int)result;
    a3[6] = 8;
    if ( (v3 & 8) != 0 )
    {
      v4 = a3;
      printk(&unk_29B41, &unk_2A972, "synx_external_callback", 53, (unsigned int)result, *a3);
      a3 = v4;
    }
    return synx_signal_handler(a3 + 14);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return printk(&unk_251CA, &unk_29207, "synx_external_callback", 43, (unsigned int)result, a2);
  }
  return result;
}
