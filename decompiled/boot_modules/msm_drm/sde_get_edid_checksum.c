__int64 __fastcall sde_get_edid_checksum(__int64 a1)
{
  unsigned __int64 v1; // x8
  void *v3; // x0

  if ( !a1 || !*(_QWORD *)a1 )
  {
    v3 = &unk_2699D0;
LABEL_8:
    printk(v3, "sde_get_edid_checksum");
    return 0;
  }
  v1 = *(_QWORD *)a1 + ((unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)a1 + 126LL) << 7);
  if ( !v1 )
  {
    v3 = &unk_270BAF;
    goto LABEL_8;
  }
  return *(unsigned __int8 *)(v1 + 127);
}
