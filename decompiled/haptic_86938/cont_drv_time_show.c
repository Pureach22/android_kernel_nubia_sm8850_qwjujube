__int64 __fastcall cont_drv_time_show(__int64 a1, int a2, char *s)
{
  return snprintf(
           s,
           0x1000u,
           "cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
           *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 1016LL),
           *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 1017LL));
}
