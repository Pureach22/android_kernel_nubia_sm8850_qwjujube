__int64 __fastcall sde_kms_get_address_space(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8

  if ( a1 )
  {
    if ( a2 <= 3 && (v2 = *(_QWORD *)(a1 + 8LL * a2 + 1704)) != 0 )
    {
      if ( *(_BYTE *)(v2 + 268) )
        return *(_QWORD *)(a1 + 8LL * a2 + 1704);
      else
        return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_234896, "_sde_kms_get_address_space");
    return 0;
  }
}
