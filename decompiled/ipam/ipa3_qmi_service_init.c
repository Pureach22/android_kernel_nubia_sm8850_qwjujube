__int64 __fastcall ipa3_qmi_service_init(int a1)
{
  ipa_wan_platform = a1;
  ipa3_qmi_modem_init_fin = 0;
  send_qmi_init_q6 = 1;
  ipa3_qmi_indication_fin = 0;
  ipa3_modem_init_cmplt = 0;
  workqueues_stopped = 0;
  if ( !ipa3_svc_handle )
  {
    ipa3_qmi_service_init_work = 0xFFFFFFFE00000LL;
    qword_200750 = (__int64)&qword_200750;
    qword_200758 = (__int64)&qword_200750;
    qword_200760 = (__int64)ipa3_qmi_service_init_worker;
    queue_work_on(32, system_wq, &ipa3_qmi_service_init_work);
  }
  return 0;
}
