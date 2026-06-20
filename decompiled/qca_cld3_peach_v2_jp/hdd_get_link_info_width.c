__int64 __fastcall hdd_get_link_info_width(_DWORD *a1)
{
  int v1; // w9
  unsigned int v2; // w8

  v1 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  v2 = 0;
  if ( v1 <= 1 )
  {
    if ( v1 )
    {
      if ( v1 != 1 )
        return v2;
LABEL_7:
      if ( (*((_QWORD *)a1 + 552) & 2) != 0 )
        return (unsigned int)a1[182];
      return 0;
    }
LABEL_9:
    if ( hdd_cm_is_vdev_associated(a1) )
      return (unsigned int)a1[233];
    return 0;
  }
  if ( v1 == 2 )
    goto LABEL_9;
  if ( v1 == 3 )
    goto LABEL_7;
  return v2;
}
