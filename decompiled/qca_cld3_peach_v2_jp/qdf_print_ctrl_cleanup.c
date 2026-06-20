__int64 __fastcall qdf_print_ctrl_cleanup(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  char *v4; // x19
  __int64 result; // x0

  if ( a1 > 0x1F )
  {
    printk(&unk_999B93, "qdf_print_ctrl_cleanup", a1, a4);
    return 16;
  }
  else
  {
    v4 = (char *)&print_ctrl_obj + 392 * a1;
    memset(v4 + 32, 0, 0x14Eu);
    result = 0;
    *((_QWORD *)v4 + 46) = 0;
    *((_QWORD *)v4 + 47) = 0;
    v4[384] = 0;
  }
  return result;
}
