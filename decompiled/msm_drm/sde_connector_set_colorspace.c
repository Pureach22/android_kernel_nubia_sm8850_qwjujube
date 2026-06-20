__int64 __fastcall sde_connector_set_colorspace(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(result + 2984);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != 282792832 )
      __break(0x8228u);
    result = v1();
    if ( (_DWORD)result )
      return printk(&unk_27DECD, "sde_connector_set_colorspace");
  }
  return result;
}
