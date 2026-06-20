__int64 __fastcall osif_cm_get_fils_auth_type(int a1)
{
  if ( (unsigned int)(a1 - 5) >= 3 )
    return 3;
  else
    return (unsigned int)(a1 - 5);
}
