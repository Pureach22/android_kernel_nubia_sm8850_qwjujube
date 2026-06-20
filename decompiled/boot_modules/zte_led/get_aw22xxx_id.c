__int64 __fastcall get_aw22xxx_id(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  size_t v8; // x0

  if ( !*a4 )
  {
    printk(&unk_1360A, "get_aw22xxx_id");
    v8 = strnlen((const char *)g_chip_id, 0x20u);
    if ( v8 >= 0x21 )
    {
      _fortify_panic(2, 32);
    }
    else if ( v8 != 32 )
    {
      return simple_read_from_buffer(a2, a3, a4, g_chip_id, v8);
    }
    _fortify_panic(4, 32);
    JUMPOUT(0xC2D0);
  }
  return 0;
}
