__int64 __fastcall check_spr_pu_feature(__int64 a1, _DWORD *a2)
{
  if ( a2 && a2[2] == 72 )
  {
    if ( **(_DWORD **)a2 >= 2u )
    {
      printk(&unk_26600B, "_check_spr_pu_feature");
    }
    else
    {
      if ( *(unsigned __int16 *)(*(_QWORD *)a2 + 44LL) - *(unsigned __int16 *)(*(_QWORD *)a2 + 40LL) == a2[11] )
        return 0;
      printk(&unk_26967E, "_check_spr_pu_feature");
    }
  }
  else
  {
    printk(&unk_277768, "_check_spr_pu_feature");
  }
  return 4294967274LL;
}
