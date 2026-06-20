__int64 mlme_cm_free_link_reconfig_done_data()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( glbl_cm_ops )
  {
    v0 = *(__int64 (**)(void))(glbl_cm_ops + 152);
    if ( v0 )
    {
      if ( *((_DWORD *)v0 - 1) != 251140989 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
