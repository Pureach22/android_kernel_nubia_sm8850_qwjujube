_QWORD *__fastcall cser_alloc(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 176);
  v1[150] = "cser";
  v1[159] = usb_cser_bind;
  v1[160] = usb_cser_unbind;
  v1[163] = usb_cser_set_alt;
  v1[165] = usb_cser_disable;
  v1[166] = usb_cser_setup;
  v1[171] = usb_cser_func_suspend;
  v1[170] = usb_cser_get_status;
  v1[151] = &usb_cser_strings;
  v1[161] = usb_cser_free_func;
  return v1 + 150;
}
