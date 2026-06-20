__int64 __fastcall cam_irq_controller_disable_all(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x9
  __int64 v6; // x8

  if ( result )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 24) )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        v4 = *(_QWORD *)(v1 + 32) + v2;
        *(_QWORD *)(v4 + 40) = 0;
        *(_QWORD *)(v4 + 48) = 0;
        v5 = *(unsigned int *)(v4 + 4);
        *(_QWORD *)(v4 + 32) = 0;
        cam_io_w_mb(0, *(_QWORD *)(v1 + 16) + v5);
        result = cam_io_w_mb(*(unsigned int *)(v1 + 60), *(_QWORD *)(v1 + 16) + *(unsigned int *)(v4 + 8));
        ++v3;
        v2 += 112;
      }
      while ( v3 < *(unsigned int *)(v1 + 24) );
    }
    v6 = *(unsigned int *)(v1 + 48);
    if ( (_DWORD)v6 )
    {
      if ( (*(_BYTE *)(v1 + 325) & 1) == 0 )
      {
        result = cam_io_w_mb(*(unsigned int *)(v1 + 52), *(_QWORD *)(v1 + 16) + v6);
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
          return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   debug_mdl & 0x800000,
                   4,
                   "cam_irq_controller_disable_all",
                   939,
                   "Global Clear done from %s",
                   (const char *)v1);
      }
    }
  }
  return result;
}
