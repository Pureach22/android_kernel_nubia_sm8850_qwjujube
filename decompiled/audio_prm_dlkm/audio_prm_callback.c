__int64 __fastcall audio_prm_callback(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // w8
  _DWORD *v3; // x20
  int v6; // w8

  v2 = a2[5];
  v3 = (unsigned int *)((char *)a2 + (((unsigned __int64)*a2 >> 2) & 0x3C));
  if ( v2 - 33558530 >= 2 )
  {
    if ( v2 == 33558533 )
    {
      printk(&unk_6E84, "audio_prm_callback");
      dword_6D60 = v3[1];
      byte_6D58 = 1;
    }
  }
  else
  {
    if ( v3[1] )
    {
      dword_6D60 = v3[1];
      printk(&unk_6EA3, "audio_prm_callback");
    }
    byte_6D58 = 1;
    if ( (unsigned int)(*v3 - 134221867) <= 7 && ((1 << (*v3 - 43)) & 0x83) != 0 || *v3 == 134224494 )
    {
      if ( v3[1] )
      {
        printk(&unk_6DE0, "audio_prm_callback");
        v6 = v3[1];
      }
      else
      {
        v6 = 0;
      }
      dword_6D5C = v6;
    }
    else
    {
      printk(&unk_6E6D, "audio_prm_callback");
    }
  }
  if ( byte_6D58 == 1 )
    _wake_up(&unk_6D10, 3, 1, 0);
  return 0;
}
