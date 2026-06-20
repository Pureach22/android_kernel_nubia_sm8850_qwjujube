__int64 __fastcall hdd_dcs_register_cb(__int64 *a1)
{
  ucfg_dcs_register_cb(*a1, (__int64)hdd_dcs_cb, (__int64)a1);
  ucfg_dcs_register_awgn_cb(*a1, (__int64)hdd_dcs_switch_chan_cb);
  return ucfg_dcs_register_afc_sel_chan_cb(*a1, (__int64)hdd_dcs_afc_sel_chan_cb, (__int64)a1);
}
