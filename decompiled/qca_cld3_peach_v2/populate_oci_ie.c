__int64 __fastcall populate_oci_ie(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int16 v13; // w21
  char v14; // w22
  char v15; // w8

  v13 = a2;
  v14 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), a2, a4, a5, a6, a7, a8, a9, a10, a11);
  v15 = lim_op_class_from_bandwidth(a1, v13, 0);
  a3[2] = v14;
  a3[1] = v15;
  a3[3] = 0;
  *a3 = 1;
  return 0;
}
