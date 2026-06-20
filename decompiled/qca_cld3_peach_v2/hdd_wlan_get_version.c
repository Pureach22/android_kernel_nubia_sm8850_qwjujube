double __fastcall hdd_wlan_get_version(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned __int8 *v12; // x11
  int v13; // w9
  int v14; // w10
  const char *v15; // x2
  double result; // d0

  if ( !a1 )
  {
    v15 = "%s: Invalid context, HDD context is null";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_wlan_get_version");
    return result;
  }
  if ( !a2 || !a3 )
  {
    v15 = "%s: Invalid buffer pointr or buffer len\n";
    goto LABEL_9;
  }
  v11 = *a1;
  if ( *a1 )
  {
    v12 = *(unsigned __int8 **)(v11 + 2800);
    if ( v12 )
    {
      LODWORD(v11) = v12[960];
      v13 = v12[961];
      v14 = v12[962];
      LODWORD(v12) = v12[963];
    }
    else
    {
      LODWORD(v11) = 0;
      v13 = 0;
      v14 = 0;
    }
  }
  else
  {
    v13 = 0;
    v14 = 0;
    LODWORD(v12) = 0;
  }
  return scnprintf(
           a3,
           a2,
           "Host SW:%s, FW:%d.%d.%d.%d.%d.%d, HW:%s, Board ver: %x Ref design id: %x, Customer id: %x, Project id: %x, Bo"
           "ard Data Rev: %x, REG DB: %u:%u, BDF REG DB: %u:%u",
           "5.2.1.137C",
           *((_DWORD *)a1 + 135),
           *((_DWORD *)a1 + 136),
           *((_DWORD *)a1 + 137),
           *((_DWORD *)a1 + 139),
           *((_DWORD *)a1 + 140),
           *((_DWORD *)a1 + 138),
           (const char *)a1 + 572,
           *((_DWORD *)a1 + 876),
           *((_DWORD *)a1 + 877),
           *((_DWORD *)a1 + 878),
           *((_DWORD *)a1 + 879),
           *((_DWORD *)a1 + 880),
           v11,
           v13,
           v14,
           (_DWORD)v12);
}
